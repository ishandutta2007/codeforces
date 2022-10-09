uses math;

var
    n: longint;
    s: ansistring;
    r, c: longint;
    i: longint;

begin
    readln(n);
    readln(s);
    r := 0;
    c := 0;
    i := 1;
    while i + 1 <= length(s) do begin
        if s[i] <> s[i + 1] then begin
            dec(n);
            inc(i);
        end;
        inc(i);
    end;
    writeln(n);
end.