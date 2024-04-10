const d: array[1..5] of longint = (100, 20, 10, 5, 1);
var
    n, i, ans: longint;
begin
    read(n);
    ans := 0;
    for i := 1 to 5 do begin
        inc(ans, n div d[i]);
        n := n mod d[i];
    end;
    writeln(ans);
end.