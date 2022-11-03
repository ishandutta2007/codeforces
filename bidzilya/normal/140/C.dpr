{$APPTYPE CONSOLE}
var
  n,ans,l,i,tmp,j,t,ind,ind1,ind2:integer;
  k,a,count:array[1..500000]of integer;
  R:array[1..500000,1..3]of integer;

procedure qsort(l,r:integer);
begin
  i:=l; j:=r; t:=k[i+random(j-i+1)];
  repeat
    while (k[i]<t)do inc(i);
    while (k[j]>t)do dec(j);
    if (i<=j)then
      begin
        tmp:=k[i];
        k[i]:=k[j];
        k[j]:=tmp;
        inc(i);
        dec(j);
      end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;

procedure heap(ind:integer);
var max:integer;
begin
  while (true)do
    begin
      max:=ind shl 1;
      if (max>l)then break;
      if (max+1<=l)and(count[k[max]]<count[k[max+1]])then max:=max+1;
      if (count[k[max]]>count[k[ind]])then
        begin
          tmp:=k[ind];
          k[ind]:=k[max];
          k[max]:=tmp;
          ind:=max;
        end
      else
        break;
    end;
end;

procedure heap1(ind:integer);
begin
  while (ind>1)and(count[k[ind shr 1]]<count[k[ind]])do
    begin
      tmp:=k[ind shr 1];
      k[ind shr 1]:=k[ind];
      k[ind]:=tmp;
      ind:=ind shr 1;
    end;
end;

begin
 { assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(n);
  for i:=1 to n do read(k[i]);
  randomize;
  qsort(1,n);

  l:=1;
  a[1]:=k[1];
  count[1]:=1;
  for i:=2 to n do
    if k[i]<>a[l]then
      begin
        inc(l);
        a[l]:=k[i];
        count[l]:=1;
      end
    else
      inc(count[l]);

  for i:=1 to l do k[i]:=i;
  for i:=l downto 1 do heap1(i);

  ans:=0;
  while (l>2)do begin
    inc(ans);
    for i:=1 to 3 do
      begin
        R[ans,i]:=k[1]; k[1]:=k[l]; dec(l); heap(1);
        dec(count[R[ans,i]]);
      end;
    for i:=1 to 3 do
      if (count[R[ans,i]]>0)then
      begin
        inc(l);
        k[l]:=R[ans,i];
        heap1(l);
      end;
  end;

  writeln(ans);
  for i:=1 to ans do
    begin
      if (A[R[i,2]]>A[R[i,1]])then
        begin
          tmp:=R[i,2];
          R[i,2]:=R[i,1];
          R[i,1]:=tmp;
        end;
      if (A[R[i,3]]>A[R[i,1]])then
        begin
          tmp:=R[i,3];
          R[i,3]:=R[i,1];
          R[i,1]:=tmp;
        end;
      if (A[R[i,3]]>A[R[i,2]])then
        begin
          tmp:=R[i,3];
          R[i,3]:=R[i,2];
          R[i,2]:=tmp;
        end;
      writeln(A[R[i,1]],' ',A[R[i,2]],' ',A[R[i,3]]);
    end;
end.