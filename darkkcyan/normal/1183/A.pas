uses math;

function sum_dig_mod_4(x: longint): longint;
begin
    if x = 0 then result := 0
    else result := (x mod 10 + sum_dig_mod_4(x div 10)) mod 4;
end;

var n: longint;
begin
    read(n);
    while sum_dig_mod_4(n) <> 0 do inc(n);
    writeln(n);
end.