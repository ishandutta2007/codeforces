program task_E;

{$APPTYPE CONSOLE}

var s: string;
    i,e,n,l,v,vv,nn,ee,m,p: integer;
begin
  readln(s);
  l:=length(s);
  e:=0;
  n:=0;
  v:=0;
  for i:=1 to l do
    if (s[i]='1')then inc(e)else
      if (s[i]='0')then inc(n)else
        inc(v);
  m:=(l-1)div 2;
  p:=(l-2)div 2;
  if (e<=m)then writeln('00');
  if (s[l]<>'0')then begin
    vv:=v;
    ee:=e;
    if (s[l]='?')then begin dec(v);inc(e);end;
    for i:=0 to v do
      if (n+i=p+1)and(e+v-i=m+1)then begin
        writeln('01');
        break;
      end;
    v:=vv;
    e:=ee;
  end;
  if (s[l]<>'1')then begin
    nn:=n;
    vv:=v;
    if (s[l]='?')then begin dec(v);inc(n);end;
    for i:=0 to v do
      if (n+i=p+1)and(e+v-i=m+1)then begin
        writeln('10');
        break;
      end;
    n:=nn;
    v:=vv;
  end;
  if (n<=p)then writeln('11');
end.