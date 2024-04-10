program TaskA;
var
    a,ins,f,i:Integer;
    n:Integer;
    c:Char;
begin
    readln(n);
    a:=0;
    ins:=0;
    f:=0;
    for i:=1 to n do
    begin
        Read(c);
        if c='A' then inc(a);
        if c='I' then inc(ins);
        if c='F' then inc(f);
    end;
    if ins >= 2 then Writeln(0);
    if ins = 1 then Writeln(1);
    if ins = 0 then Writeln(a);
    end.