uses math;

var
    n: longint;
    s: ansistring;
    i: longint;
    ans: longint;
    
begin
    readln(n);
    readln(s);
    ans := 0;
    for i := 1 to n - 1 do begin
        if s[i] <> s[i + 1] then begin
            if s[i] = 'S' then inc(ans)
            else dec(ans);
        end;
    end;
    if ans > 0 then writeln('YES')
    else writeln('NO')
end.