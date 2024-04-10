var
n, i: integer;
a: array[0..1] of ansistring;

begin
{$ifndef ONLINE_JUDGE}
    assign(input, 'in.txt');   reset(input);
    assign(output, 'out.txt'); rewrite(output);
{$endif}
    readln(n);
    writeln((n * n + 1) div 2);
    a[0] := ''; a[1] := '';
    for i := 1 to n do begin
        a[i mod 2] := a[i mod 2] + 'C';
        a[(i + 1) mod 2] := a[(i + 1) mod 2] + '.';
    end;
    for i := 1 to n do begin
        writeln(a[i mod 2]);
    end;
end.