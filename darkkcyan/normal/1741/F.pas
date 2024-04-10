uses math;

type segment = record
    l, r, c: longint;
    id: longint;
end;

type seg_cmp = function(const u: segment; const v: segment): boolean;

function cmp_by_l(const u: segment; const v: segment): boolean;
begin
    exit(u.l < v.l);
end;
function cmp_by_r(const u: segment; const v: segment): boolean;
begin
    exit(u.r < v.r);
end;

procedure swap_seg(var u, v: segment);
var t: segment;
begin
    t := u; u := v; v := t;
end;

procedure sort(var a: array of segment; const cmp: seg_cmp);
var
    i: longint;
    end_lower, start_upper: longint;
    pivot: segment;
begin
    if length(a) <= 1 then exit();
    pivot := a[random(length(a))];
    end_lower := 0;
    start_upper := length(a);
    i := 0;
    while i < start_upper do begin
        if cmp(a[i], pivot) then begin
            swap_seg(a[i], a[end_lower]);
            inc(end_lower);
            inc(i);
        end else if cmp(pivot, a[i]) then begin
            dec(start_upper);
            swap_seg(a[i], a[start_upper]);
        end else inc(i);
    end;
    sort(a[0..end_lower - 1], cmp);
    sort(a[start_upper..high(a)], cmp);
end;

const maxn = 201010;

var
    n: longint;
    it: array[0..maxn * 2] of longint;

procedure build_it;
var i: longint;
begin
    for i := 0 to 2 * n do it[i] := -1;
end;

procedure upd(i: longint; val: longint);
begin
    inc(i, n);
    it[i] := max(it[i], val);
    i := i div 2;
    while i > 0 do begin
        it[i] := max(it[2 * i], it[2 * i + 1]);
        i := i div 2;
    end;
end;

function get_max(l, r: longint): longint;
var ans: longint;
begin
    ans := -1;
    inc(l, n);
    inc(r, n);
    while l < r do begin
        if l mod 2 = 1 then begin
            ans := max(ans, it[l]);
            inc(l);
        end;
        if r mod 2 = 1 then begin
            dec(r);
            ans := max(ans, it[r]);
        end;
        l := l div 2;
        r := r div 2;
    end;
    exit(ans);
end;

var
    ntest: longint;
    a: array[0..maxn] of segment;
    b: array[0..maxn] of segment;
    i, f: longint;
    ans: array[0..maxn] of longint;
    max_r: longint;
    turn: longint;
    t: longint;

const inf = 1000 * 1000 * 1000 + 1000;

begin
    read(ntest);
    while ntest > 0 do begin
        // writeln(stderr, '===');
        dec(ntest);
        read(n);
        max_r := 0;
        for i := 1 to n do begin
            read(a[i].l, a[i].r, a[i].c);
            a[i].id := i;
            dec(a[i].c);
            max_r := max(max_r, a[i].r);
        end;
        for i := 1 to n do ans[i] := inf;
        for turn := 1 to 2 do begin
            sort(a[1..n], cmp_by_l);
            for i := 1 to n do begin
                b[i] := a[i];
            end;
            sort(b[1..n], cmp_by_r);
            // writeln(stderr, 'segment');
            // for i := 1 to n do begin
                // writeln(stderr, a[i].l, ' ', a[i].r, ' ', a[i].c, ' ', a[i].id);
            // end;
            
            build_it;
            i := 1;
            f := 1;
            // writeln(stderr, 'processing');
            for i := 1 to n do begin
                while (f <= n) and (a[f].l <= b[i].r) do begin
                    upd(a[f].c, a[f].r);
                    inc(f);
                end;
                t := max(get_max(0, b[i].c), get_max(b[i].c + 1, n));
                // writeln(stderr, b[f].id, ' ', b[f].l, ' ', b[f].r, ' ' , b[f].c, ' ', t);
                if t <> -1 then begin
                    ans[b[i].id] := min(ans[b[i].id], max(0, b[i].l - t));
                end;
            end;
            
            for i := 1 to n do begin
                a[i].l := max_r - a[i].l + 1;
                a[i].r := max_r - a[i].r + 1;
                t := a[i].l;
                a[i].l := a[i].r;
                a[i].r := t;
            end;
            // writeln(stderr, 'segment reversed');
            // for i := 1 to n do begin
                // writeln(stderr, a[i].l, ' ', a[i].r, ' ', a[i].c, ' ', a[i].id);
            // end;
        end;
        
        for i := 1 to n do write(ans[i], ' ');
        writeln;
    end;
end.