program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
  m=1000;
var
  two,five:array[0..m,0..m] of Integer;
  tc,fc:array[1..m,1..m] of Char;
  t,f,n,i,j,r,x,y,zerox,zeroy:Integer;
  stwo,sfive:String;
  zero:Boolean;
begin
 { Assign(Input,'input.txt');
  Reset(Input);
  Assign(Output,'output.txt');
  Reset(Output);  }
  for i:=0 to m do
  begin
    for j:=0 to m do
    begin
      two[i,j]:=0;
      five[i,j]:=0;
    end;
  end;
  zero:=false;
  for i:=0 to m do
  begin
    two[0,i]:=1000000000;
    two[i,0]:=1000000000;
    five[0,i]:=1000000000;
    five[i,0]:=1000000000;
  end;
  two[0,1]:=0;
  five[0,1]:=0;
  Readln(n);
  // i-lines, j-columns
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(r);
      if r=0 then
      begin
        zero:=true;
        zerox:=i;
        zeroy:=j;
        r:=10;
      end;
      t:=0;
      f:=0;
      while (r mod 2)=0 do
      begin
        Inc(t);
        r:=r div 2;
      end;
      while (r mod 5)=0 do
      begin
        Inc(f);
        r:=r div 5;
      end;
      if two[i-1,j]<two[i,j-1] then
      begin
        two[i,j]:=Two[i-1,j]+t;
        tc[i,j]:='D';
      end
      else
      begin
        two[i,j]:=Two[i,j-1]+t;
        tc[i,j]:='R';
      end;
      if five[i-1,j]<five[i,j-1] then
      begin
        five[i,j]:=five[i-1,j]+f;
        fc[i,j]:='D';
      end
      else
      begin
        five[i,j]:=five[i,j-1]+f;
        fc[i,j]:='R';
      end;
    end;
  end;
  Stwo:='';
  Sfive:='';
  x:=n; y:=n;
  while ((x>1) or (y>1)) do
  begin
    if tc[x,y]='D' then
    begin
      X:=X-1;
      sTWO:='D'+stwo;
    end
    else
    begin
      y:=y-1;
      stwo:='R'+stwo;
    end;
  end;
  x:=n; y:=n;
  while ((x>1) or (y>1)) do
  begin
    if fc[x,y]='D' then
    begin
      x:=X-1;
      sfive:='D'+sfive;
    end
    else
    begin
      y:=y-1;
      sfive:='R'+sfive;
    end;
  end;
  if (two[n,n]>0) and (five[n,n]>0) and (zero) then
  begin
    Writeln(1);
    for i:=2 to zerox do
      Write('D');
    for i:=2 to zeroy do
      Write('R');
    for i:=zerox+1 to n do
      write('D');
    for i:=zeroy+1 to n do
      Write('R');
    Halt(0);
  end;
  if two[n,n]<five[n,n] then
  begin
    Writeln(two[n,n]);
    Writeln(stwo);
  end
  else
  begin
    Writeln(five[n,n]);
    Writeln(sfive);
  end;
 // Readln(n);
 { Close(Input);
  Close(Output);}
end.