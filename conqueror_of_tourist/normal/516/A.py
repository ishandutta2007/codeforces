#Better than Bestwillcui could ever do

l = [[],[],['2'],['3'],['2','2','3'],['5'],['3','5'],['7'],['2','2','2','7'],['7','3','3','2']]
a = list()

input()
inp = input()
for x in inp:
    a += l[int(x)]
a.sort(reverse = True)
print(''.join(a))