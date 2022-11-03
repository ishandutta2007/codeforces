program D;

{$APPTYPE CONSOLE}

var n,m,buf:integer;
begin
  read(n,m);
  if (m<n)then begin
    buf:=n;
    n:=m;
    m:=buf;
  end;
  if (n=1)then begin
    write(m);
    halt;
  end;
  if (n=2)then begin
    if (m mod 4=1)or(m mod 4=3)then inc(m,1)else
      if (m mod 4=2)then inc(m,2);
    write(m);
    halt;
  end;
  write((m*n+1)div 2);
end.