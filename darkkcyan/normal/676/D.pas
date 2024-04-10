const maxn = 1111;
const dir = '*<^ >- Dv |R UL+';
var
    n, m: longint;
    a: array[0..maxn, 0..maxn] of byte;
    rt, ct, rm, cm: longint;
    i, f, g: longint;
    s: ansistring;

var
    dst: array[0..maxn, 0..maxn, 0..3] of longint;
    qu: array[0..maxn * maxn * 5] of int64;
    h, t: longint;

function rotate(s, d: longint): longint;
begin exit((s shl 4 or s) shr (4 - d) and 15); end;

procedure pushstate(r, c, d, ndst: int64);
begin
    if (dst[r][c][d] <> -1) then exit;
    dst[r][c][d] := ndst;
    inc(t);
    qu[t] := (r shl 12) + (c shl 2) + d;
end;

procedure nextstate(r, c, d: longint);
const
    dr: array[0..3] of shortint = (0, -1, 0, 1);
    dc: array[0..3] of shortint = (-1, 0, 1, 0);
var
    i, tr, tc: longint;
    s, t: longint;
begin
    s := rotate(a[r][c], d);
    for i := 0 to 3 do begin
        tr := r + dr[i];
        tc := c + dc[i];
        if (tr > n) or (tr < 1) or (tc > m) or (tc < 1) then continue;
        t := rotate(a[tr][tc], d);
        //writeln(stderr, r, ' ', c, ' ', tr, ' ', tc, ' ', d, ' ', s, ' ', t);
        if (((s shr i) and 1) = 0) then continue;
        if ((((t shr (i xor 2))) and 1) = 0) then continue;
        //writeln(stderr, tr, ' ', tc);
        pushstate(tr, tc, d, dst[r][c][d] + 1);
    end;
    pushstate(r, c, (d + 1) and 3, dst[r][c][d] + 1);
end;

function bfs: longint;
var
    x: int64;
    r, c, d: longint;
begin
    fillchar(dst, sizeof(dst), 255);
    h := 0; t := -1;
    pushstate(rt, ct, 0, 0);
    while h <= t do begin
        x := qu[h]; inc(h);
        d := x and ((1 shl 2) - 1); x := x shr 2;
        c := x and ((1 shl 10) - 1); x := x shr 10;
        r := x;
        //writeln(stderr, r, ' ', c, ' ', d, ' ', dst[r][c][d]);
        if (r = rm) and (c = cm) then exit(dst[r][c][d]);
        nextstate(r, c, d);
    end;
    exit(-1);
end;

begin
    readln(n, m);
    for i := 1 to n do begin
        readln(s);
        for f := 1 to m do begin
            for g := 1 to length(dir) do
                if s[f] = dir[g] then begin
                    a[i][f] := g - 1;
                    //writeln(stderr, i, ' ', f, ' ', g - 1);
                    break;
                end;
        end;
    end;
    readln(rt, ct);
    readln(rm, cm);
    writeln(bfs);
end.