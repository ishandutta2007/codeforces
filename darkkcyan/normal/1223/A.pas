uses math;

var
    q: longint;
    n: longint;
    ans: longint;

begin
    read(q);
    while (q > 0) do begin
        dec(q);
        read(n);
        ans := 0;
        if n mod 2 = 1 then begin
            inc(n);
            inc(ans);
        end;
        if n div 2 = 1 then begin
            inc(ans, 2);
            inc(n, 2);
        end;
        writeln(ans);
    end;
end.