program task_e;

{$APPTYPE CONSOLE}
uses Math;
const nmax = 100000;
var Head,Mn,Mx: array[1..nmax*2]of integer;
    T,x,y,Next,P: array[1..nmax]of integer;
    Ans: array[0..8]of integer;
    i,j,n,m,ty,tx,tt: integer;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  read(n,m);
  for i:=1 to m do begin
    read(y[i],x[i]);
    T[i]:=0;
  end;
  for i:=1 to n do begin
    Head[i]:=-1;
    Mn[i]:=maxint;
    Mx[i]:=-maxint;
  end;
  for i:=1 to m do begin
    Next[i]:=Head[y[i]];
    Head[y[i]]:=i;
  end;
  for i:=1 to n do begin
    j:=Head[i];
    while (j<>-1)do begin
      Mn[i]:=min(Mn[i],x[j]);
      Mx[i]:=max(Mx[i],x[j]);
      j:=Next[j];
    end;
  end;
  for i:=1 to m do
    if (x[i]<>Mn[y[i]])and(x[i]<>Mx[y[i]])then inc(T[i],2)else
      if (x[i]=Mn[y[i]])and(x[i]<>Mx[y[i]])then inc(T[i])else
        if (x[i]=Mx[y[i]])and(x[i]<>Mn[y[i]])then inc(T[i]);

  for i:=1 to n do begin
    Head[i]:=-1;
    Mn[i]:=maxint;
    Mx[i]:=-maxint;
  end;
  for i:=1 to m do begin
    Next[i]:=Head[x[i]];
    Head[x[i]]:=i;
  end;
  for i:=1 to n do begin
    j:=Head[i];
    while (j<>-1)do begin
      Mn[i]:=min(Mn[i],y[j]);
      Mx[i]:=max(Mx[i],y[j]);
      j:=Next[j];
    end;
  end;
  for i:=1 to m do
    if (y[i]<>Mn[x[i]])and(y[i]<>Mx[x[i]])then inc(T[i],2)else
      if (y[i]=Mn[x[i]])and(y[i]<>Mx[x[i]])then inc(T[i])else
        if (y[i]=Mx[x[i]])and(y[i]<>Mn[x[i]])then inc(T[i]);
  for i:=1 to 2*n-1 do begin
    Head[i]:=-1;
    Mn[i]:=maxint;
    Mx[i]:=-maxint;
  end;
  for i:=1 to m do begin
    tt:=min(x[i],y[i])-1;
    ty:=y[i]-tt;
    tx:=x[i]-tt;
    if (tx=1)then p[i]:=n-ty+1
    else p[i]:=n+tx-1;
    Next[i]:=Head[P[i]];
    Head[P[i]]:=i;
  end;
  for i:=1 to 2*n-1 do begin
    j:=Head[i];
    while (j<>-1)do begin
      Mn[i]:=min(Mn[i],y[j]);
      Mx[i]:=max(Mx[i],y[j]);
      j:=Next[j];
    end;
  end;
  for i:=1 to m do
    if (y[i]<>Mn[P[i]])and(y[i]<>Mx[P[i]])then inc(T[i],2)else
      if (y[i]=Mn[P[i]])and(y[i]<>Mx[P[i]])then inc(T[i])else
        if (y[i]=Mx[P[i]])and(y[i]<>Mn[P[i]])then inc(T[i]);
  for i:=1 to 2*n-1 do begin
    Head[i]:=-1;
    Mn[i]:=maxint;
    Mx[i]:=-maxint;
  end;
  for i:=1 to m do begin
    tt:=min(y[i]-1,n-x[i]);
    ty:=y[i]-tt;
    tx:=x[i]+tt;
    if (ty = 1)then p[i]:=tx
      else p[i]:=n+ty-1;
    Next[i]:=Head[P[i]];
    Head[P[i]]:=i;
  end;
  for i:=1 to 2*n-1 do begin
    j:=Head[i];
    while (j<>-1)do begin
      Mn[i]:=min(Mn[i],y[j]);
      Mx[i]:=max(Mx[i],y[j]);
      j:=Next[j];
    end;
  end;
  for i:=1 to m do
    if (y[i]<>Mn[P[i]])and(y[i]<>Mx[P[i]])then inc(T[i],2)else
      if (y[i]=Mn[P[i]])and(y[i]<>Mx[P[i]])then inc(T[i])else
        if (y[i]=Mx[P[i]])and(y[i]<>Mn[P[i]])then inc(T[i]);
  for i:=0 to 8 do Ans[i]:=0;
  for i:=1 to m do
    inc(Ans[T[i]]);
  for i:=0 to 8 do
    write(Ans[i],' ');
end.