program tmp_4;

{$APPTYPE CONSOLE}
const nmax = 100000;
var Next,T,W,ok:array[1..2*nmax]of integer;
    d,Head,p,op:array[1..nmax]of integer;
    a,b,c:array[1..nmax]of integer;
    l,i,n,s,m,len,k,v1,v2,j,min,buf:integer;
    ans:int64;

procedure up(ind:integer);
var midl,buf:integer;
begin
  while ind>1 do begin
    midl:=ind div 2;
    if d[p[midl]]>d[p[ind]]then begin
      buf:=p[midl]; p[midl]:=p[ind]; p[ind]:=buf;
      buf:=op[p[midl]]; op[p[midl]]:=op[p[ind]]; op[p[ind]]:=buf;
      ind:=midl;
    end else exit;
  end;
end;

procedure down(ind:integer);
var midl,buf:integer;
begin
  while ind*2<=len do begin
    midl:=ind*2;
    if (midl+1<=len)and(d[p[midl+1]]<d[p[midl]])then midl:=midl+1;
    if (d[p[midl]]<d[p[ind]])then begin
      buf:=p[ind]; p[ind]:=p[midl]; p[midl]:=buf;
      buf:=op[p[ind]]; op[p[ind]]:=op[p[midl]]; op[p[midl]]:=buf;
      ind:=midl;
    end
     else exit;
  end;
end;

begin
 // assign(input,'input.txt');reset(input);
 // assign(output,'output.txt');rewrite(output);
  readln(n,m,s);
  for i:=1 to n do Head[i]:=-1;
  for i:=1 to m do begin
    readln(v1,v2,k);
    Next[i]:=Head[v1];
    Head[v1]:=i;
    W[i]:=k;
    T[i]:=v2;

    Next[i+m]:=Head[v2];
    Head[v2]:=i+m;
    W[i+m]:=k;
    T[i+m]:=v1;

    a[i]:=v1;
    b[i]:=v2;
    c[i]:=k;
  end;
  readln(l);
  for i:=1 to n do d[i]:=maxint;
  d[s]:=0;
  ans:=0;
  len:=1;
  p[1]:=s;
  op[s]:=1;
  for i:=1 to n do if (i<>s)then begin
    inc(len);
    p[len]:=i;
    op[i]:=len;
  end;
  while (true)do begin
    if (len=0)then break;
    min:=p[1];
    p[1]:=p[len];
    op[p[1]]:=1;
    dec(len);
    down(1);
    if (d[min]=l)then inc(ans);
    i:=Head[min];
    while (i<>-1)do begin
      if (d[min]+w[i]<d[T[i]])then begin
        d[T[i]]:=d[min]+w[i];
        up(op[T[i]]);
      end;
      i:=Next[i];
    end;
  end;
  for i:=1 to m do begin
    if (d[b[i]]<l)and(d[a[i]]<l)and(d[a[i]]+d[b[i]]+c[i]=2*l)then begin inc(ans); continue; end;
    if (d[a[i]]<l)and(l-d[a[i]]<c[i])and(c[i]-l+d[a[i]]+d[b[i]]>l)then inc(ans);
    if (d[b[i]]<l)and(l-d[b[i]]<c[i])and(c[i]-l+d[b[i]]+d[a[i]]>l)then inc(ans);
  end;
  write(ans);
end.