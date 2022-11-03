program task_1;
{$apptype console r+ q+ o+}
uses SysUtils, Math;
type real = extended;
var y1,y2,t1,t2,x1,x2,t0: int64;
    anst: real;
procedure binary;
var m,ll,rr,mm: int64;
    tp: real;
begin
  m:=0;
  while (m<=x1)do begin
    ll:=0;rr:=x2;
    while (ll<=rr)do begin
      mm:=(ll+rr)shr 1;
      if (m=0)and(mm=0)then break;
      tp:=(t1*m+t2*mm)/(m+mm);
      if (tp>=t0)and
        ((tp<anst)or((tp=anst)and(m+mm>y1+y2)))then begin
          y1:=m;
          y2:=mm;
          anst:=tp;
        end;
      if (tp>t0)then rr:=mm-1
        else ll:=mm+1;
    end;
    inc(m);
  end;
end;

begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  read(t1,t2,x1,x2,t0);
  y1:=0;
  y2:=0;
  anst:=1e9;
  binary;
  if (y1=0)then y2:=x2;
  if (y2=0)then y1:=x1;
  write(y1,' ',y2);
end.