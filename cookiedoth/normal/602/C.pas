program TwoWays;
var
  matrix,matrix2:array[1..800,1..800] of Boolean;
  met:array[1..800] of Integer;
  i,j,n,m,u,versh,komax,ko:Integer;
  color:array[1..800] of Integer;
  o:array[1..801] of Integer;
begin
    for i:=1 to 400 do
    begin
      for j:=1 to 400 do
      begin
        matrix[i,j]:=false;
        matrix2[i,j]:=True;
      end;
      met[i]:=8888;
      color[i]:=0;
    end;
    met[1]:=0;
    Readln(n,m);
    for i:=1 to m do
    begin
      Readln(u,versh);
      matrix[u,versh]:=true;
      matrix[versh,u]:=true;
      matrix2[u,versh]:=False;
      matrix2[versh,u]:=false;
    end;
    if matrix[1,n]=True then
    begin
      matrix:=matrix2;
    end;
    color[1]:=1;
    o[1]:=1;
    komax:=1;
    ko:=0;
    while ko<komax do
    begin
      Inc(ko);
      for i:=1 to n do
      begin
        if (matrix[o[ko],i]=True) and (color[i]<1) then
        begin
          color[i]:=1;
          Inc(komax);
          o[komax]:=i;
          if met[i]>met[o[ko]]+1 then met[i]:=met[o[ko]]+1;
        end;
      end;
      color[o[ko]]:=2;
    end;
    if met[n]=8888 then
    begin
      Writeln(-1);
      Halt(0);
    end;
    Writeln(met[n]);
end.