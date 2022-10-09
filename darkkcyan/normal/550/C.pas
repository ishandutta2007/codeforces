uses math;
var
    s: string;
    len: integer;
    i, f, g: integer;
    num: integer;

procedure output(ans: integer);
begin
    writeln('YES');
    writeln(ans);
    halt;
end;

begin
    readln(s);
    len := length(s);
    for i := 1 to len do begin
        if s[i] <> '0' then continue;
        writeln('YES');
        writeln('0');
        halt;
    end;
    
    for i := 1 to len do begin
        num := ord(s[i]) - ord('0');
        if num mod 8 = 0 then output(num);
        for f := i + 1 to len do begin
            num := num * 10 + ord(s[f]) - ord('0');
            if num mod 8 = 0 then output(num);
            for g := f + 1 to len do begin
                num := num * 10 + ord(s[g]) - ord('0');
                if num mod 8 = 0 then output(num);
                num := num div 10;
            end;
            num := num div 10;
        end;
    end;
    writeln('NO');
end.