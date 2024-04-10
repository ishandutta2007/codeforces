var
n, m: integer;
a, ans: array[0..101010] of integer;
mark: array[0..101010] of boolean;
i: integer;

begin
{$ifndef ONLINE_JUDGE}
    assign(input, 'in.txt');   reset(input);
    assign(output, 'out.txt'); rewrite(output);
{$endif}
    readln(n, m);
    for i := 1 to n do read(a[i]);
    fillchar(mark, sizeof(mark), 0);
    fillchar(ans, sizeof(ans), 0);
    for i := n downto 1 do begin
        ans[i] := ans[i + 1];
        if (mark[a[i]]) then continue;
        mark[a[i]] := true;
        inc(ans[i]);
    end;
    for i := 1 to m do begin
        readln(n);
        writeln(ans[n]);
    end;
end.