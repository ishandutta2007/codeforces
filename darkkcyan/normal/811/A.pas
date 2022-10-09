uses math;

var
    a, b: int64;
    s: int64;

begin
    readln(a, b);
    s := 1;
    while true do begin
        if (s mod 2 = 1) then begin
            dec(a, s);
            if (a < 0) then break;
        end else begin
            dec(b, s);
            if (b < 0) then break;
        end;
        inc(s);
    end;
    if (a < 0) then writeln('Vladik')
    else writeln('Valera');
end.