uses math;

var
    s: ansistring;
    ntest: longint;
    ans, i, l, r: longint;
begin
    readln(ntest);
    while ntest > 0 do begin
        dec(ntest);
        readln(s);
        for l := 1 to length(s) do if s[l] = '1' then break;
        for r := length(s) downto 1 do if s[r] = '1' then break;
        if l >= r then begin
            writeln(0);
            continue;
        end;
        ans := 0;
        for i := l to r do begin
            if s[i] = '0' then inc(ans);
        end;
        writeln(ans);
    end;
end.