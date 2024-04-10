program task_2;

{$apptype console r+ q+}
const maxint = round(1e5);
var s,ans: string;
    k,i,j,pp,tp,p: integer;
    Head: array[0..1,'a'..'z']of integer;
    Sum,cnt: array['a'..'z']of int64;
    Next: array[0..1,1..maxint]of integer;
    n: int64;
    it,c: char;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(s);
  n:=length(s);
  read(k);
  if ((n+1)*n div 2<k)then begin
    writeln('No such line.');
    halt;
  end;
  ans:='';
  fillchar(Head[0],sizeof(Head[0]),-1);
  fillchar(Sum,sizeof(Sum),0);
  fillchar(Cnt,sizeof(Cnt),0);
  for i:=1 to n do begin
    Next[0,i]:=Head[0,s[i]];
    Head[0,s[i]]:=i;
    inc(Sum[S[i]],n-i+1);
    inc(Cnt[S[i]]);
  end;
  pp:=0;
  while (true)do begin
    for it:='a' to 'z' do
      if (k<=Sum[it])then begin
        c:=it;
        break;
      end else dec(k,Sum[it]);
    ans:=ans+c;
    if (k<=cnt[c])then break else dec(k,cnt[c]);
    tp:=(pp+1)mod 2;
    fillchar(Sum,sizeof(Sum),0);
    fillchar(Cnt,sizeof(cnt),0);
    fillchar(Head[tp],sizeof(Head[tp]),-1);
    i:=Head[pp,c];
    while (i<>-1)do begin
      p:=i+1;
      inc(Sum[s[p]],n-p+1);
      inc(Cnt[s[p]]);
      Next[tp,p]:=Head[tp,s[p]];
      Head[tp,s[p]]:=p;

      i:=Next[pp,i];
    end;
    pp:= tp;
  end;
  writeln(ans);
end.