uses math;
const maxn = 111;
var
    n: longint;
    c: array [0..maxn]of char;

function count(i: longint): longint;
begin
    if i >= n then exit(0);
    result := count(i + 1) + byte(c[i] + c[i - 1] + c[i - 2] = 'xxx');
end;
    
begin
    readln(n);
    readln(c);
    writeln(count(2));
end.