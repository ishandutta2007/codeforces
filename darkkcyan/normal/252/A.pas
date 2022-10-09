const mxn = 111;
var
a: array[1..mxn] of longint;
n: longint;

i, f: longint;
ans, cur: longint;

begin
    readln(n);
    for i := 1 to n do read(a[i]);
    ans := 0;
    for i := 1 to n do begin
        cur := 0;
        for f := i to n do begin
            cur := cur xor a[f];
            if ans < cur then ans := cur;
        end;
    end;
    writeln(ans);
end.