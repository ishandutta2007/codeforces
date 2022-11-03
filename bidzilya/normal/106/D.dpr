uses SysUtils;
type Tbox = record
  c:char;
  x,y:integer;
end;
var
  o:array[1..26]of Tbox;
  a:array[0..1001,0..1001]of char;
  xl,xp,yv,yn:array[0..1001,0..1001]of integer;
  k,n,m,i,num,zn,j:integer;
  s:string;
  np:char;
  ok:boolean;
  tmp:Tbox;
  
begin
  //assign(input,'input.txt'); reset(input);
  readln(n,m);
  num:=0;
  for i:=0 to n+1 do begin
    a[0,i]:='#';
    yv[0,i]:=0;
    a[n+1,i]:='#';
    yn[n+1,i]:=0;
    a[i,0]:='#';
    xl[i,0]:=0;
    a[i,n+1]:='#';
    xp[i,n+1]:=0;
  end;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i,j]);
      if (a[i,j]<>'#')and(a[i,j]<>'.')then begin
        inc(num);
        o[num].c:=a[i,j];
        a[i,j]:='.';
        o[num].x:=j;
        o[num].y:=i;
      end;
    end;
    readln;
  end;
  
  for i:=1 to n do 
    for j:=1 to m do 
      if a[i,j]='#' then begin
        xl[i,j]:=0;
        yv[i,j]:=0;
      end else begin
        xl[i,j]:=xl[i,j-1]+1;
        yv[i,j]:=yv[i-1,j]+1;
      end;
  for i:=n downto 1 do
    for j:=m downto 1 do
      if a[i,j]='#' then begin
        xp[i,j]:=0;
        yn[i,j]:=0;
      end else begin
        xp[i,j]:=xp[i,j+1]+1;
        yn[i,j]:=yn[i+1,j]+1;
      end;
  
  readln(k);
  for i:=1 to k do begin
    readln(s);
    np:=s[1];
    delete(s,1,2);
    zn:=strtoint(s);
    j:=1;
    while j<=num do begin
      ok:=true;
      if np='N' then begin
        if yv[o[j].y,o[j].x]<=zn then ok:=false else o[j].y:=o[j].y-zn;
      end else
        if np='S' then begin
          if yn[o[j].y,o[j].x]<=zn then ok:=false else o[j].y:=o[j].y+zn;
        end else
          if np='W' then begin
            if xl[o[j].y,o[j].x]<=zn then ok:=false else o[j].x:=o[j].x-zn;
          end else
            if np='E' then begin
              if xp[o[j].y,o[j].x]<=zn then ok:=false else o[j].x:=o[j].x+zn;
            end;
      if not ok then begin
        o[j]:=o[num];
        dec(num);
      end else inc(j);
    end;
  end;

  if num=0 then write('no solution') else 
  begin
    for i:=1 to num-1 do
      for j:=i+1 to num do
        if o[j].c<o[i].c then begin
          tmp:=o[i];
          o[i]:=o[j];
          o[j]:=tmp;
        end;
    for i:=1 to num do
      write(o[i].c);
  end;
end.