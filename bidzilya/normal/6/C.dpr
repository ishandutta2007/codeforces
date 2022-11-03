program project1;

{$apptype console}

uses Math, SysUtils;
var t: array[1..100000]of integer;
    n,i,j,a,b,aa,ab: integer;
    inc_a,inc_b: boolean;

begin
  read(n);
  for i:=1 to n do
    read(t[i]);
  a:=1;b:=n;
  aa:=0;ab:=0;
  inc_a:=true;inc_b:=true;
  while (true)do begin
    if (b<a)then break;
    if (a=b)then begin
      if (inc_a)and(inc_b)then
        inc(aa)
      else
      if (inc_b)and(not inc_a)then
        inc(aa)
      else
      if (inc_a)and(not inc_b)then
        inc(ab);
      break;
    end;
    dec(t[b]);
    if (t[b]=0)then begin
      inc(ab);
      dec(b);
      inc_b:=true;
    end else
      inc_b:=false;
    dec(t[a]);
    if (t[a]=0)then begin
      inc(aa);
      inc(a);
      inc_a:=true;
    end else
      inc_a:=false;
  end;
  writeln(aa,' ',ab);
end.