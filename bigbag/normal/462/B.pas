uses math;

var n, k, x, ans : int64;
    i, j : longint;
    a : array[0..26] of int64;
    s : string;
begin
    readln(n, k);
    readln(s);
    for i := 1 to length(s) do
        inc(a[ord(s[i]) - ord('A')]);
    for i := 0 to 25 do 
        for j := i + 1 to 25 do
            if a[i] > a[j] then 
            begin
                x := a[i];
                a[i] := a[j];
                a[j] := x;
            end;
    for i := 25 downto 0 do
    begin
        x := min(k, a[i]);
        ans := ans + x * x;
        k := k - x;
    end;
    writeln(ans);
end.