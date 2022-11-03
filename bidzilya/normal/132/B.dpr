program task_d;

{$APPTYPE CONSOLE}
uses Math,SysUtils;
var h,m,n,tmp,tb,cnt,i,j,tpx,tpy,newx,newy: integer;
    bl,map: array[0..51,0..51]of integer;
    bl_lf,bl_rg,bl_dn,bl_up: array[1..50*50]of integer;
    dp,cp: char;
    s: string;
procedure go(y,x: integer);
begin
  bl[y,x]:=cnt;
  if (y>1)and(map[y-1,x]=map[y,x])and(bl[y-1,x]=-1)then go(y-1,x);
  if (y<n)and(map[y+1,x]=map[y,x])and(bl[y+1,x]=-1)then go(y+1,x);
  if (x>1)and(map[y,x-1]=map[y,x])and(bl[y,x-1]=-1)then go(y,x-1);
  if (x<m)and(map[y,x+1]=map[y,x])and(bl[y,x+1]=-1)then go(y,x+1);
end;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(n,h);
  for i:=1 to n do begin
    readln(s);
    for j:=1 to length(s)do
      map[i,j]:=strtoint(s[j]);
  end;
  m:=length(s);
  for i:=0 to n+1 do
    for j:=0 to m+1 do
      bl[i,j]:=-1;
  cnt:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (bl[i,j]=-1)and(map[i,j]<>0)then begin
        inc(cnt);
        bl_lf[cnt]:=m+1;
        bl_rg[cnt]:=0;
        bl_up[cnt]:=n+1;
        bl_dn[cnt]:=0;
        go(i,j);
      end;
  for i:=1 to n do
    for j:=1 to m do begin
      tmp:=bl[i,j];
      if (tmp<>-1)then begin
        bl_lf[tmp]:=min(bl_lf[tmp],j);
        bl_rg[tmp]:=max(bl_rg[tmp],j);
        bl_up[tmp]:=min(bl_up[tmp],i);
        bl_dn[tmp]:=max(bl_dn[tmp],i);
      end;
    end;
  tpx:=1;tpy:=1;
  dp:='R';cp:='L';
  for h:=1 to h do begin
    tb:=bl[tpy,tpx];

    if (dp='R')then begin
      newx:=bl_rg[tb]+1;
      if (cp='L')then
        newy:=bl_up[tb]
      else
        newy:=bl_dn[tb];
    end;
    if (dp='L')then begin
      newx:=bl_lf[tb]-1;
      if (cp='L')then
        newy:=bl_dn[tb]
      else
        newy:=bl_up[tb];
    end;
    if (dp='U')then begin
      newy:=bl_up[tb]-1;
      if (cp='L')then
        newx:=bl_lf[tb]
      else
        newx:=bl_rg[tb];
    end;
    if (dp='D')then begin
      newy:=bl_dn[tb]+1;
      if (cp='L')then
        newx:=bl_rg[tb]
      else
        newx:=bl_lf[tb];
    end;

    if (bl[newy,newx]<>-1)then begin
      tpx:=newx;
      tpy:=newy;
      continue;
    end;
    if (cp='L')then cp:='R'
    else begin
      cp:='L';
      if (dp='L')then dp:='U' else
        if (dp='U')then dp:='R' else
          if (dp='R')then dp:='D' else
            if (dp='D')then dp:='L';
    end;
  end;
  write(map[tpy,tpx]);
end.