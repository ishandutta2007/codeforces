program task_1;
{$apptype console r+ q+}
uses Math,SysUtils;
var n,mn,mx,t,i,ans: integer;
begin
  read(n);
  read(mn);
  mx:=mn;
  ans:=0;
  for i:=2 to n do begin
    read(t);
    if (t>mx)then begin
      mx:=t;
      inc(ans);
    end;
    if (t<mn)then begin
      mn:=t;
      inc(ans);
    end;
  end;
  write(ans);
end.