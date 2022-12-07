const
  eps=1e-8;
var
  ans:integer;
  a,b:real;
  function sig(a:real):integer;
  begin
    if a<-eps then exit(-1) else
    if a>eps then exit(1) else exit(0)
  end;
begin
  readln(a,b);
  b:=b/a; a:=1;
  ans:=trunc(b)*2;
  b:=b-trunc(b);
  if sig(b-(sqrt(3)/2))>=0 then ans:=ans+3
  else if sig(b-0.5)>=0 then ans:=ans+2
  else inc(ans);
  writeln(ans);
end.