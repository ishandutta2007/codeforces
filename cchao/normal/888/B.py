input()
s = raw_input()
print (min(s.count('L'), s.count('R')) + min(s.count('U'), s.count('D'))) * 2