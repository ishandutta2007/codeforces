program tmp_2;

{$APPTYPE CONSOLE}

var
    x,y,r:array[1..1000]of integer;
    n,buf,x1,y1,x2,y2,i,j,ans:integer;
    l:real;
    ok:boolean;
begin
  readln(x1,y1,x2,y2);
  if (x2<x1)then begin
    buf:=x1;
    x1:=x2;
    x2:=buf;
  end;
  if (y2<y1)then begin
    buf:=y1;
    y1:=y2;
    y2:=buf;
  end;
  readln(n);
  for i:=1 to n do begin
    readln(x[i],y[i],r[i]);
    r[i]:=r[i]*r[i];
  end;
  ans:=0;
  for i:=x1 to x2 do begin
    ok:=true;
    for j:=1 to n do begin
      l:=sqr(i-x[j])+sqr(y1-y[j]);
      if (l<=r[j])then begin
        ok:=false;
        break;
      end;
    end;
    if (ok)then inc(ans);
    ok:=true;
    for j:=1 to n do begin
      l:=sqr(i-x[j])+sqr(y2-y[j]);
      if (l<=r[j])then begin
        ok:=false;
        break;
      end;
    end;
    if (ok)then inc(ans);
  end;
  for i:=y1+1 to y2-1 do begin
    ok:=true;
    for j:=1 to n do begin
      l:=sqr(x1-x[j])+sqr(i-y[j]);
      if (l<=r[j])then begin
        ok:=false;
        break;
      end;
    end;
    if (ok)then inc(ans);
    ok:=true;
    for j:=1 to n do begin
      l:=sqr(x2-x[j])+sqr(i-y[j]);
      if (l<=r[j])then begin
        ok:=false;
        break;
      end;
    end;
    if (ok)then inc(ans);
  end;
  write(ans);
  read(n);
end.