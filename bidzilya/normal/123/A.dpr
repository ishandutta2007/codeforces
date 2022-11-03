{$APPTYPE CONSOLE}

var c:char;
    cnt:array[1..26]of integer;
    sim:array[1..26]of char;
    ans:array[1..1000]of char;
    l,j,ind,i,szl,tmp,t:integer;

function prime(x:integer):boolean;
var i:integer;
begin
  for i:=2 to round(sqrt(x))do
    if x mod i=0 then begin prime:=false; exit; end;
  prime:=true;
end;

begin
  {assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(c); l:=0; szl:=0;
  fillchar(cnt,sizeof(cnt),0);
  while (c in ['a'..'z'])do
  begin
    inc(szl);
    ind:=-1;
    for i:=1 to l do if sim[i]=c then begin ind:=i; break; end;
    if ind=-1 then begin inc(l); sim[l]:=c; cnt[l]:=1; end
    else inc(cnt[ind]);
    read(c);
  end;
  fillchar(ans,sizeof(ans),'0');
  ind:=1;
  for j:=2 to l do if cnt[j]>cnt[ind] then ind:=j;
  for i:=2 to szl div 2 do
    if (prime(i))then
    begin
      t:=i;
      while t<=szl do
      begin
        if ans[t]='0'then
        begin
          if cnt[ind]=0 then begin writeln('NO'); halt; end;
          dec(cnt[ind]);
          ans[t]:=sim[ind];
        end;
        t:=t+i;
      end;
    end;

  writeln('YES');
  for i:=1 to szl do
  begin
    if ans[i]='0' then
    begin
      ind:=1;
      while (cnt[ind]=0)do inc(ind);
      ans[i]:=sim[ind];
      dec(cnt[ind]);
    end;
    write(ans[i]);
  end;
end.