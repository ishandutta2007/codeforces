var
s: ansistring;
i, ans: integer;
m: array['a'..'z'] of boolean;

begin
{$ifndef ONLINE_JUDGE}
    assign(input, 'in.txt');  reset(input);
    assign(output, 'out.txt'); rewrite(output);
{$endif}
    readln(s);
    ans := 0;
    fillchar(m, sizeof(m), 0);
    for i := 1 to length(s) do begin
        if (s[i] >= 'a') and (s[i] <= 'z') then begin
            if not m[s[i]] then begin
                m[s[i]] := true;
                inc(ans);
            end;
        end;
    end;
    writeln(ans);
end.