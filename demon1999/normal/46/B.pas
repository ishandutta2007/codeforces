const
D: array[1..5,1..5] of byte = ((1,2,3,4,5),(2,3,1,4,5),(3,4,2,5,1),(4,5,3,2,1),(5,4,3,2,1));
var
mas: array[1..5] of integer;
i,j,n,x,z: integer;
s: string;
fl: boolean;

begin
for i:=1 to 5 do read(mas[i]);
readln;
readln(n);
for i:=1 to n do begin
    readln(s);
    if  s='S' then x:=1;
    if  s='M' then x:=2;
    if s ='L' then x:=3;
    if s= 'XL' then x:=4;
    if s= 'XXL' then x:=5;

    fl:=false;
    j:=0;
    while fl=false do begin
        inc(j);
        if mas[d[x,j]]>0 then fl:=true;
        end;
    dec(mas[d[x,j]]);
    j:=d[x,j];
    case j of
      1: writeln('S');
      2: writeln('M');
      3: writeln('L');
      4: writeln('XL') ;
      5: writeln('XXL');
      end;
    end;
end.