tot = 0
try:
    ppl = 0
    while True:
        com = input()
        if com[0] == "+":
            ppl += 1
        elif com[0] == "-":
            ppl -= 1
        elif ':' in com:
            tot += (ppl*len(':'.join(com.split(':')[1:])))
except:
    print(tot)