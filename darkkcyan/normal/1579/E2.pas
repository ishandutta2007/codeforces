uses math;

const maxn = 202020;

var buff: array[0..maxn] of longint;
procedure sort(var a: array of longint);
var
    i, f, mid, cur: longint;
begin
    if length(a) <= 1 then exit();
    mid := length(a) div 2;
    sort(a[0..mid - 1]);
    sort(a[mid..length(a) - 1]);
    
    f := mid;
    cur := 0;
    for i := 0 to mid - 1 do begin
        while (f < length(a)) and (a[f] < a[i]) do begin
            buff[cur] := a[f];
            inc(cur);
            inc(f);
        end;
        buff[cur] := a[i];
        inc(cur);
    end;
    for i := f to high(a) do begin
        buff[cur] := a[i];
        inc(cur);
    end;
    
    for i := 0 to high(a) do a[i] := buff[i];
    // for i := 0 to high(a) do write(stderr, a[i], ' ');  
    // writeln(stderr); 
end;

function bin_search(var a: array of longint; val: longint): longint;
var
    l, r, mid: longint;
begin
    l := 0;
    r := length(a);
    while l < r do begin
        mid := l + (r - l) div 2;
        if a[mid] >= val then r := mid
        else l := mid + 1;
    end;
    exit(l);
end;

var
    bit: array[0..maxn] of longint;
    
procedure bit_upd(i, d: longint);
begin
    inc(i);
    while i <= maxn do begin
        inc(bit[i], d);
        inc(i, i and (-i));
    end;
end;

function bit_get(i: longint): longint;
var ans: longint;
begin
    ans := 0;
    inc(i);
    while i > 0 do begin
        inc(ans, bit[i]);
        dec(i, i and (-i));
    end;
    exit(ans);
end;

var
    ntest: longint;
    n: longint;
    a, b: array[0..maxn] of longint;
    i: longint;
    cnt_sm, cnt_bg: longint;
    ans: int64;

begin
    read(ntest);
    while ntest > 0 do begin
        // writeln(stderr, '==='); 
        dec(ntest);
        read(n);
        for i := 1 to n do begin
            read(a[i]);
            b[i] := a[i];
        end;
        sort(b[1..n]);
        // writeln(stderr, n); 
        // for i := 1 to n do begin 
            // write(stderr, i, ':', b[i], ' '); 
        // end; 
        // writeln(stderr); 
        for i := 1 to n do begin
            a[i] := bin_search(b[1..n], a[i]);
            // write(stderr, a[i], ' '); 
        end;
        // writeln(stderr); 
        
        for i := 1 to min(2 * n, maxn) do bit[i] := 0;
        
        ans := 0;
        for i := 1 to n do begin
            cnt_sm := bit_get(a[i] - 1);
            cnt_bg := (i - 1) - bit_get(a[i]);
            inc(ans, min(cnt_sm, cnt_bg));
            bit_upd(a[i], 1);
        end;
        writeln(ans);
        
    end;
end.