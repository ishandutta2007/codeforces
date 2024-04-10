program task_2;

{$apptype console}
{$r+ q+ o+}
uses
  SysUtils, Math;
var map: array[1..150,1..150]of char;
    Head: array[1..150]of integer;
    Next,T: array[1..150*150]of integer;
    ans,n,m,l,r,i,j,len,yy,x,y: integer;
    tn,nn: char;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(n,m);
  fillchar(Head,sizeof(Head),-1);
  len:=0;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(map[i,j]);
      if (map[i,j] = 'W')then begin
        inc(len);
        Next[len]:=Head[i];
        Head[i]:=len;
        T[len]:=j;
      end;
    end;
    readln;
  end;
  ans:=0;
  y:=1; x:=1; tn:='R';
  yy:=1;
  while (true) do begin
    while (yy <= n)and(Head[yy] = -1)do inc(yy);
    if (yy > n)then break;
    l:=m;r:=1;
    j:=Head[yy];
    while (j<>-1)do begin
      l:=min(l,T[j]);
      r:=max(r,T[j]);
      j:=Next[j];
    end;
    j:=yy-y;
    ans:=ans+j;
    j:=j mod 2;
    nn:=tn;
    if (j = 1)and(tn = 'R')then nn:='L' else
      if (j = 1)and(tn = 'L')then nn:='R' else
        nn:=tn;
    if (nn = 'R')then begin
      if (x > l)then begin
        ans:=ans+x-l;
        x:=l;
      end;
      ans:=ans+r-x;
      x:=r;
    end;
    if (nn = 'L')then begin
      if (x < r)then begin
        ans:=ans+r-x;
        x:=r;
      end;
      ans:=ans+x-l;
      x:=l;
    end;
    y:=yy;tn:=nn;
    inc(yy);
  end;
  write(ans);
end.