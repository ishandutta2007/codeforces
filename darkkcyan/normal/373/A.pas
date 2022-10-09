var
a: array['1'..'9'] of integer;
k, i, f: integer;
s: string;

begin
{$ifndef ONLINE_JUDGE}
    assign(input, 'in.txt');   reset(input);
    assign(output, 'out.txt'); rewrite(output);
{$endif}
    readln(k); inc(k, k);
    fillchar(a, sizeof(a), 0);
    for i := 1 to 4 do begin
        readln(s);
        for f := 1 to 4 do 
            if (s[f] <> '.') then inc(a[s[f]]);
    end;
    for i := 1 to 9 do begin
        if a[chr(i + ord('0'))] > k then begin
            writeln('NO');
            halt;
        end;
    end;
    writeln('YES');
end.