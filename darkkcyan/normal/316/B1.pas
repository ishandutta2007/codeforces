uses math;
const maxn = 1111;
var p, cnt: array [0..maxn] of longint;
function findp(u: longint): longint;
begin
    if p[u] <> u then p[u] := findp(p[u]);
    exit(p[u]);
end;

procedure join(u, v: longint);
begin
    u := findp(u);
    v := findp(v);
    if u = v then exit();
    p[u] := v;
    inc(cnt[v], cnt[u]);
end;

var
    a: array[0..maxn] of longint;
    c: array[0..maxn] of boolean;
    n, x: longint;
    i, f, g, t: longint;
begin
    readln(n, x);
    for i := 1 to n do begin
        p[i] := i;
        cnt[i] := 1;
    end;
    for i := 1 to n do begin
        read(a[i]);
        if a[i] <> 0 then join(i, a[i]);
    end;
    t := 1;
    g := x;
    while a[g] <> 0 do begin
        inc(t);
        g := a[g];
    end;
    g := 0;
    fillchar(c, sizeof(c), 0);
    c[0] := true;
    for i := 1 to n do begin
        if (i <> findp(i)) or (findp(i) = findp(x)) then continue;
        for f := maxn - cnt[i] downto 0 do begin
            if c[f] then c[f + cnt[i]] := true;
        end;
    end;
    for i := 0 to maxn do 
        if c[i] then writeln(i + t);
end.