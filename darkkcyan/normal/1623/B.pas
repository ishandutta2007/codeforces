uses math;

const maxn = 1010;

var
    ntest: longint;
    n: longint;
    l, r: array[0..maxn] of longint;
    mark: array[0..maxn, 0..maxn] of boolean;
    i, j, d: longint;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do
        for j := 1 to n do begin
            mark[i][j] := false;
        end;
        for i := 1 to n do begin
            read(l[i], r[i]);
            mark[l[i]][r[i]] := true;
        end;
        for i := 1 to n do begin
            for d := l[i] to r[i] do begin
                if ((d = l[i]) or mark[l[i]][d - 1]) and ((d = r[i]) or mark[d + 1][r[i]]) then begin
                   writeln(l[i], ' ', r[i], ' ', d);
                   break;
               end;
            end;
        end;
    end;
end.