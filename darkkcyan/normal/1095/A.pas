uses math;
var
    n, i: integer;
    s: string;

begin
    readln(n);
    readln(s);
    for i := 1 to n do 
        if i * (i + 1) div 2 > n then break
        else write(s[i * (i + 1) div 2]);
end.