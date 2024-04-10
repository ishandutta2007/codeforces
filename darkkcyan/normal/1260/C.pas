uses math;
function gcd(a, b: int64): int64;
begin
    if b = 0 then exit(a);
    exit(gcd(b, a mod b));
end;

function lcm(a, b: int64): int64;
begin
    exit(a div gcd(a, b) * b);
end;

var
    ntest: longint;
    r, b, k: int64;
    l, nr, nb: int64;


begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(r, b, k);
        l := lcm(r, b);
        nr := l div r;
        nb := l div b;
        if ((nr - 1) div nb + byte((nr - 1) mod nb > 0) < k) and ((nb - 1) div nr + byte((nb - 1) mod nr > 0) < k) then
            writeln('OBEY')
        else 
            writeln('REBEL');
    end;
end.