program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,i,j,ans: integer;
    a: array[1..100]of integer;

begin
  read(n);
  for i:=1 to 100 do a[i]:=0;
  for i:=1 to n do begin
    read(j);
    inc(a[j]);
  end;
  ans:=0;
  for i:=1 to 100 do begin
    ans:=ans+a[i]div 4;
    a[i]:=a[i] mod 4;
  end;
  for i:=1 to 100 do
    for j:=i+1 to 100 do
      if (a[i]>=2)and(a[j]>=2)then begin
        dec(a[i],2);
        dec(a[j],2);
        inc(ans);
      end;
  write(ans);
end.