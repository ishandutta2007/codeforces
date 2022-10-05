works = True
inp = input()
left = len(inp.split('('))-1
right = len(inp.split(')'))-1
symb = len(inp.split('#'))-1
diff = left - right
if diff <= 0:
    works = False
l = []
for x in range(symb-1):
    l.append(1)
l.append(diff - symb + 1)
st = inp.split('#')
n = st.pop()
st = ")".join(st)
for x in range(l[-1]):
    st = st + ')'
st += n
left = 0
right = 0
for x in st:
    if x == '(':
        left += 1
    else:
        right += 1
    if right > left:
        works = False
        break
if works:
    for x in l:
        print(x)
else:
    print(-1)