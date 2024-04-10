uses math;
const maxn = 101010;
var
a: array[0..maxn] of longint;
it, lz: array[0..maxn * 4] of int64;

procedure build(i, l, r: longint);
var
mid: longint;
begin
    if l = r then it[i] := a[l];
    if l >= r then exit();
    mid := (l + r) div 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    it[i] := max(it[i * 2], it[i * 2 + 1]);
end;

procedure diffuse(i, l, r: longint);
begin
    if (l > r) or (lz[i] = 0) then exit();
    it[i] := max(it[i], lz[i]);
    if (l < r) then begin
        lz[i * 2] := max(lz[i * 2], lz[i]);
        lz[i * 2 + 1] := max(lz[i * 2 + 1], lz[i]);
    end;
    lz[i] := 0;
end;

procedure update(i, l, r, u, v: longint; val: int64);
var
mid: longint;
begin
    // writeln(stderr, i, ' ', l, ' ', r);
    diffuse(i, l, r);
    if (l > r) or (l > v) or (u > r) then exit();
    if (u <= l) and (r <= v) then begin
        lz[i] := max(it[i], val);
        diffuse(i, l, r);
        exit();
    end;
    mid := (l + r) div 2;
    update(i * 2, l, mid, u, v, val);
    update(i * 2 + 1, mid + 1, r, u, v, val);
    it[i] := max(it[i * 2], it[i * 2 + 1]);
end;

function query(i, l, r, u, v: longint): int64;
var
mid: longint;
begin
    // writeln(stderr, i, ' ', l, ' ', r);
    diffuse(i, l, r);
    if (l > r) or (l > v) or (u > r) then exit(-1);
    if (u <= l) and (r <= v) then exit(it[i]);
    mid := (l + r) div 2;
    exit(max(
        query(i * 2, l, mid, u, v),
        query(i * 2 + 1, mid + 1, r, u, v)
    ));
end;

var
n, m, u, v: int64;
i: longint;
t: int64;
begin
    readln(n);
    for i := 1 to n do read(a[i]);
    fillchar(lz, sizeof(lz), 0);
    build(1, 1, n);
    readln(m);
    while m > 0 do begin dec(m);
        readln(u, v);
    // writeln(stderr, 'OK', m);
        t := query(1, 1, n, 1, u);
        writeln(t);
        update(1, 1, n, 1, u, t + v);
    // writeln(stderr, 'OK', m);
    end;
end.