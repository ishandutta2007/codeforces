var
    ntest: longint;
    a, b: ansistring;
    line: ansistring;

function cal_rank(const x: ansistring): longint;
var res: longint;
begin
    res := 100;
    if x = 'M' then exit(res);
    if x[length(x)] = 'S' then exit(res - length(x));
    exit(res + length(x));
end;

var 
ra, rb: longint;
i: longint;

begin
    readln(ntest);
    while ntest > 0 do begin
        dec(ntest);
        readln(line);
        a := '';
        b := '';
        for i := 1 to length(line) do begin
            if line[i] = ' ' then break;
            a := a + line[i];
        end;
        for i := i + 1 to length(line) do begin
            b := b + line[i];
        end;
        ra := cal_rank(a);
        rb := cal_rank(b);
        if ra = rb then writeln('=')
        else if ra < rb then writeln('<')
        else writeln('>');
    end;
end.