program B;

{$APPTYPE CONSOLE}
var vp,vd,t,f,c,ans: integer;
    pp,tt: real;
begin
  read(vp,vd,t,f,c);
  ans:=0;
  if (vd<=vp)then begin
    write(ans);
    halt;
  end;
  pp:=t*vp;
  while (pp<c)do begin
    tt:=pp/(vd-vp);
    if (tt<(c-pp)/vp)then begin
      inc(ans);
      pp:=pp+(f+2*tt)*vp;
    end else break;
  end;
  write(ans);
end.