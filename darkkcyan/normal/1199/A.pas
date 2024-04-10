uses math;

function min_element(a: array of longint) : longint;
begin
    if length(a) = 0 then result := high(longint)
    else result := min(a[0], min_element(a[1..high(a)]));
end;

const maxn = 101010;
var
    n, x, y: longint;
    a: array [0..maxn] of longint;
    i: longint;

begin
    read(n, x, y);
    for i := 1 to n do read(a[i]);
    for i := 1 to n do begin
        if a[i] >= min_element(a[max(1, i - x)..i - 1]) then continue;
        if a[i] >= min_element(a[i + 1 .. min(n, i + y)]) then continue;
        writeln(i);
        break;
    end;
end.