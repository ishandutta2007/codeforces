program task_3;

{$APPTYPE CONSOLE}
uses SysUtils;
var k,n,m,q,i,p,j,t,l:integer;
    sost,bas:array[1..100]of string;
    art,have,ansh:array[1..100,0..200]of integer;
    ans:array[1..100,1..200]of string;
    s:string;

function getind(s:string):integer;
var i:integer;
begin
  for i:=1 to n do
    if (bas[i]=s)then begin
      getind:=i;
      exit;
    end;
end;

procedure add(ind,p:integer);
var name:string;
    i,h:integer;
begin
  name:='';
  i:=1;
  while (s[i]<>' ')do begin
    name:=name+s[i];
    inc(i);
  end;
  inc(i);
  h:=0;
  while (i<p)do begin
    h:=h*10+ord(s[i])-ord('0');
    inc(i);
  end;
  i:=getind(name);
  art[ind,i]:=art[ind,i]+h;
end;

procedure check(ind:integer);
var i,j:integer;
    ok,found:boolean;
begin
  for i:=1 to m do begin
    ok:=true;
    for j:=1 to n do
      if (have[ind,j]<art[i,j])then begin
        ok:=false;
        break;
      end;
    if (ok)then begin
      for j:=1 to n do
        have[ind,j]:=have[ind,j]-art[i,j];
      found:=false;
      for j:=1 to ansh[ind,0]do
        if (ans[ind,j]=sost[i])then begin
          inc(ansh[ind,j]);
          found:=true;
          break;
        end;
      if (not found)then begin
        inc(ansh[ind,0]);
        ans[ind,ansh[ind,0]]:=sost[i];
        ansh[ind,ansh[ind,0]]:=1;
      end;
      exit;
    end;
  end;
end;

begin
 // assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(k,n,m,q);
  for i:=1 to n do readln(bas[i]);
  for i:=1 to m do begin
    readln(s);
    p:=pos(':',s);
    sost[i]:=copy(s,1,p-1);
    delete(s,1,p+1);
    for j:=1 to n do art[i,j]:=0;
    s:=s+', ';
    p:=pos(',',s);
    while (p<>0)do begin
      add(i,p);
      delete(s,1,p+1);
      p:=pos(',',s);
    end;
  end;
  for i:=1 to k do
    for j:=1 to n do
      have[i,j]:=0;
  for i:=1 to k do ansh[i,0]:=0;
  for i:=1 to q do begin
    readln(s);
    p:=pos(' ',s);
    l:=strtoint(copy(s,1,p-1));
    delete(s,1,p);
    j:=getind(s);
    have[l,j]:=have[l,j]+1;
    check(l);
  end;
  for i:=1 to k do
    for j:=1 to n do
      if (have[i,j]<>0)then begin
        inc(ansh[i,0]);
        ansh[i,ansh[i,0]]:=have[i,j];
        ans[i,ansh[i,0]]:=bas[j];
      end;
  for i:=1 to k do
    for j:=1 to ansh[i,0]-1 do
      for l:=j+1 to ansh[i,0]do
        if (ans[i,l]<ans[i,j])then begin
          s:=ans[i,l];
          ans[i,l]:=ans[i,j];
          ans[i,j]:=s;
          t:=ansh[i,l];
          ansh[i,l]:=ansh[i,j];
          ansh[i,j]:=t;
        end;
  for i:=1 to k do begin
    writeln(ansh[i,0]);
    for j:=1 to ansh[i,0]do
      writeln(ans[i,j],' ',ansh[i,j]);
  end;
end.