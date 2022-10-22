a=raw_input().split("WUB")
t=False
g=""
for x in a:
	if x=="":
		continue
	if x!="":
		g+=x
		g+=" "
		

print g.strip()