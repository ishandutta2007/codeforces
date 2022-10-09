program c1;
var ans: array [1..1000] of integer;
var n, i, k, l, n1, ansq: integer;
begin
ansq := 0;
readln (n);
for i:=2 to n do begin
    k := i;
    l := 1;
    n1 := 0;
    while (k > 1) and (n1 < 2) do begin
        l := l + 1;
        if (k mod l = 0) then begin
                n1 := n1 + 1;
                while (k mod l = 0) do k := k div l;
        end;
    end;
    if n1 < 2 then begin
        ansq := ansq + 1;
        ans[ansq] := i;
    end;
end;
writeln (ansq);
for i := 1 to ansq do write (ans[i], ' ');
end.