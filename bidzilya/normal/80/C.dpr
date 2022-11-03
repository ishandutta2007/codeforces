uses Math;
const name:array[1..7] of string=('Anka','Chapay','Cleo','Troll','Dracul','Snowy','Hexadecimal');
var
  matr:array[1..7,1..7]of byte;
  k1,k2,k3:array[1..5]of byte;
  num1,num2,num3:byte;
  zn1,zn2,zn3,tp,a,b,c,mn,mx,ans,i,j,p,k:integer;
  name1,name2,s:string;
  tmp:real;
  
procedure rec(v,c1,c2,c3:integer);
var i,j,tans:integer;
begin
  if v>7 then begin
    tans:=0; 
    for i:=1 to num1 do 
      for j:=1 to num1 do
        if matr[k1[i],k1[j]]=1 then inc(tans);
    for i:=1 to num2 do
      for j:=1 to num2 do
        if matr[k2[i],k2[j]]=1 then inc(tans);
    for i:=1 to num3 do
      for j:=1 to num3 do
        if matr[k3[i],k3[j]]=1 then inc(tans);
    if tans>ans then
      ans:=tans;
  end;
  if c1>0 then begin
    k1[c1]:=v;
    rec(v+1,c1-1,c2,c3);
  end;
  if c2>0 then begin
    k2[c2]:=v;
    rec(v+1,c1,c2-1,c3);
  end;
  if c3>0 then begin
    k3[c3]:=v;
    rec(v+1,c1,c2,c3-1);
  end;
end;

begin
  //assign(input,'input.txt');
  //reset(input);
  readln(p);
  for i:=1 to p do begin
    readln(s);
    name1:='';
    name2:='';
    j:=length(s);
    while s[j]<>' ' do begin
      name2:=s[j]+name2;
      dec(j);
    end;
    j:=1;
    while s[j]<>' ' do begin
      name1:=name1+s[j];
      inc(j);
    end;
    for j:=1 to 7 do
      if name[j]=name1 then a:=j else
        if name[j]=name2 then b:=j;
    matr[a,b]:=1;
  end;
  read(a,b,c);
  ans:=maxint;
  mn:=maxint;
  mx:=-maxint;
  for i:=1 to 5 do begin
    tp:=7-i;
    p:=tp;
    for j:=1 to tp-1 do begin
      p:=tp-j;
      tmp:=a/i;
      zn1:=round(tmp);
      if zn1>tmp then dec(zn1);
      tmp:=b/j;
      zn2:=round(tmp);
      if zn2>tmp then dec(zn2);
      tmp:=c/p;
      zn3:=round(tmp);
      if zn3>tmp then dec(zn3);
      mx:=max(zn1,max(zn2,zn3));
      mn:=min(zn1,min(zn2,zn3));
      if mx-mn<ans then begin
        ans:=mx-mn;
        num1:=i;
        num2:=j;
        num3:=p;
      end;
    end;
  end;
  write(ans,' ');
  
  k:=ans;
  ans:=0;
  for i:=1 to 5 do begin
    tp:=7-i;
    p:=tp;
    for j:=1 to tp-1 do begin
      p:=tp-j;
      tmp:=a/i;
      zn1:=round(tmp);
      if zn1>tmp then dec(zn1);
      tmp:=b/j;
      zn2:=round(tmp);
      if zn2>tmp then dec(zn2);
      tmp:=c/p;
      zn3:=round(tmp);
      if zn3>tmp then dec(zn3);
      mx:=max(zn1,max(zn2,zn3));
      mn:=min(zn1,min(zn2,zn3));
      if mx-mn=k then begin
        num1:=i;
        num2:=j;
        num3:=p;
        rec(1,num1,num2,num3);
      end;
    end;
  end;
  write(ans);
end.