uses math;

function sum_dig(n: longint): longint;
begin
    if n = 0 then exit(0);
    exit(n mod 10 + sum_dig(n div 10));
end;

var k: longint;
var i: longint;

begin
    read(k);
    i := 18;
    repeat
        inc(i);
        if sum_dig(i) = 10 then dec(k)
    until k = 0;
    writeln(i);
end.