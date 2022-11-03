program task_c;

{$apptype console}
uses Math;
var l: integer;
    n,j,x: int64;
    s,a: array[1..100000]of int64;

begin
  read(x);
  n:=x;
  l:=0;
  j:=2;
  while (j<=round(power(x,1/2)))do begin
    if (x mod j=0)then begin
      inc(l);
      a[l]:=j;
      s[l]:=0;
      while (x mod j=0)do begin
        inc(s[l]);
        x:=x div j;
      end;
    end;
    inc(j);
  end;
  if (l=0)then begin
    writeln(1);
    writeln(0);
  end else
  if (l=1)and(s[1]>1)and(a[1]*a[1]<>n)then begin
    writeln(1);
    writeln(a[1]*a[1]);
  end else
  if (l>1)and(a[1]*a[2]<>n)then begin
    writeln(1);
    writeln(a[1]*a[2]);
  end else
    writeln(2);
end.