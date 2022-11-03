program C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var min,max,k,n,len:int64;
    d:array[1..10000]of int64;
    i,c1,c2,c3:integer;
begin
  read(n); len:=0;
  for i:=1 to n do begin
    if (i*i>n)then break;
    if (n mod i=0)then begin
      inc(len);
      d[len]:=i;
      if (i*i<n)then begin
        inc(len);
        d[len]:=n div i;
      end;
    end;
  end;
  min:=trunc(9e18);
  max:=0;
  for c1:=1 to len do
    for c2:=1 to len do
      if (n div d[c1] mod d[c2]=0)then begin
        c3:=n div d[c1] div d[c2];
        k:=int64((d[c1]+1)*(d[c2]+2)*(c3+2));
        if (k<min)then min:=k;
        if (k>max)then max:=k;
      end;
  write(min-n,' ',max-n);
end.