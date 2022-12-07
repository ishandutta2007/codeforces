var
  n,m,s,f,i,now,t,l,r,j,step:longint;
function ok(p,l,r:longint):boolean;
begin
  if not((p>=l)and(p<=r)) then exit(true)
  else exit(false);
end;
begin
  readln(n,m,s,f);
  now:=s;
  for i:=1 to m do
  begin
    read(t,l,r);  inc(step);
    if now=f then continue;
    for j:=step to t-1 do
    begin
    if now>f then begin now:=now-1; write('L'); end else
    if now<f then begin now:=now+1; write('R'); end;
    if now=f then break;
    end;
    step:=t;
    if now=f then continue;
    if (now>f)and ok(now,l,r) and ok(now-1,l,r) then
    begin now:=now-1; write('L'); end else
    if (now<f)and ok(now,l,r) and ok(now+1,l,r) then
    begin now:=now+1; write('R'); end else
    write('X');
  end;
  if now<f then for i:=now to f-1 do write('R');
  if now>f then for i:=f to now-1 do write('L');
  writeln;
end.