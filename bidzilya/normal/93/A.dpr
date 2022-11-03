var
  a,b,m,n:integer;
  ra,rb,ma,mb,ans:integer;

begin
  read(n,m,a,b);
  ra:=a div m;
  ma:=a mod m;
  if ma=0 then ma:=m;
  if ra*m<a then inc(ra);
  rb:=b div m;
  mb:=b mod m;
  if mb=0 then mb:=m;
  if rb*m<b then inc(rb);
  
  if (ma=1)and((mb=m)or(b=n))then ans:=1 else
    if ra=rb then ans:=1 else
      if (ma=1)or(mb=m)or(b=n) then ans:=2 else
        if mb=ma-1 then ans:=2 else
          if ra=rb-1 then ans:=2 else ans:=3;
  write(ans);
end.