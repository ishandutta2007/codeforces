var
pos,n,i:integer;
s:string;
c:array[1..100000] of integer;
b:array[1..100000] of boolean;
begin
    readln(n);
    readln(s);
    for i:=1 to n do
    begin
        read(c[i]);
        if s[i]='<' then c[i]:=-c[i];
        b[i]:=false;
    end;
    pos:=1;
    while (pos>0) and (pos<n+1) do
    begin
        if b[pos]=true then
        begin
            write('INFINITE');
            halt(0);
        end;
        b[pos]:=true;
        inc(pos,c[pos]);
    end;
    write('FINITE');
end.