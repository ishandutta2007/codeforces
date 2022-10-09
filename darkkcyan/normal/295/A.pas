procedure add(var a: array of int64; i: longint; v: int64);
begin
    while i <= high(a) do begin
        inc(a[i], v);
        inc(i, i and (-i));
    end;
end;

function get(var a: array of int64; i: longint): int64;
var
    ans: int64 = 0;
begin
    while i > 0 do begin
        inc(ans, a[i]);
        dec(i, i and (-i));
    end;
    exit(ans);
end;

const maxn = trunc(1e5 + 100);
var
    n, m, k: longint;
    a, b, l, r, d: array[0..maxn] of int64;
    i, f, g: longint;

begin
    readln(n, m, k);
    fillchar(a, sizeof(a), 0);
    fillchar(b, sizeof(b), 0);
    for i := 1 to n do begin
        read(f);
        add(a, i, f);
        add(a, i + 1, -f);
    end;
    for i := 1 to m do begin
        read(l[i], r[i], d[i]);
    end;
    for i := 1 to k do begin
        read(f, g);
        add(b, f, 1);
        add(b, g + 1, -1);
    end;
    for i := 1 to m do begin
        add(a, l[i], d[i] * get(b, i));
        add(a, r[i] + 1, -d[i] * get(b, i));
    end;
    for i := 1 to n do 
        write(get(a, i), ' ');
end.